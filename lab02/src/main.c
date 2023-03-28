#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>
#include <Lmcons.h>

#pragma warning(disable: 4996)

#define fatal_error(fmt, ...) do { error(fmt, __VA_ARGS__); exit(1); } while (0)

static void error(const char* const fmt, ...) {
	va_list args;
	va_start(args, fmt);
	printf("ERROR: ");
	vprintf(fmt, args);
	printf("\n");
	va_end(args);
}

static char* time_to_string(SYSTEMTIME* time) {
	char* buffer = NULL;
	size_t size = 0;
retry:
	size_t len = 1 + snprintf(buffer, size,
		"%4hu/%02hu/%02hu %02hu:%02hu:%02hu\n",
		time->wYear, time->wMonth, time->wDay,
		time->wHour, time->wMinute, time->wSecond
	);
	if (buffer) {
		return buffer;
	}

	buffer = malloc(len);
	size = len - 1;
	goto retry;
}

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	LRESULT result = 0;
	switch (msg) {

		case WM_DESTROY: PostQuitMessage(0); break;

		default: {
			result = DefWindowProcA(hwnd, msg, wparam, lparam);
		} break;
	}
	return result;
}

int main() {
	char computer_name[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
	DWORD bytes = sizeof(computer_name);
	if (!GetComputerNameA(computer_name, &bytes)) {
		fatal_error("unable to get computer name (code %lu)", GetLastError());
	}

	char username[UNLEN + 1] = { 0 };
	if (!GetUserNameA(username, &bytes)) {
		fatal_error("unable to get username (code %lu)", GetLastError());
	}

	char sys_dir[MAX_PATH] = { 0 };
	if (!GetSystemDirectoryA(sys_dir, sizeof(sys_dir))) {
		fatal_error("unable to get system directory path (code %lu)", GetLastError());
	}

	char win_dir[MAX_PATH] = { 0 };
	if (!GetWindowsDirectoryA(win_dir, sizeof(win_dir))) {
		fatal_error("unable to get Windows directory path (code %lu)", GetLastError());
	}

	char temp_path[MAX_PATH] = { 0 };
	if (!GetTempPathA(sizeof(temp_path), temp_path)) {
		fatal_error("unable to get temporary path (code %lu)", GetLastError());
	}

	OSVERSIONINFOA version_info = { sizeof(OSVERSIONINFOA) };
	if (!GetVersionExA(&version_info)) {
		fatal_error("unable to get version information (code %lu)", GetLastError());
	}

	BOOL beeper_enabled;
	if (!SystemParametersInfoA(SPI_GETBEEP, 0, &beeper_enabled, 0)) {
		fatal_error("unable to get SPI_GETBEEP parameter (code %lu)", GetLastError());
	}

	BOOL font_smoothing;
	if (!SystemParametersInfoA(SPI_GETFONTSMOOTHING, 0, &font_smoothing, 0)) {
		fatal_error("unable to get SPI_GETFONTSMOOTHING parameter (code %lu)", GetLastError());
	}

	BOOL mouse_shadow;
	if (!SystemParametersInfoA(SPI_GETCURSORSHADOW, 0, &mouse_shadow, 0)) {
		fatal_error("unable to get SPI_GETCURSORSHADOW parameter (code %lu)", GetLastError());
	}

	SYSTEMTIME system_time, local_time;
	GetSystemTime(&system_time);
	GetLocalTime(&local_time);

	printf("Computer name         : %s\n", computer_name);
	printf("User name             : %s\n", username);
	printf("System directory path : %s\n", sys_dir);
	printf("Windows directory path: %s\n", win_dir);
	printf("Temporary path        : %s\n", temp_path);
	printf("Windows version       : %lu.%lu\n", version_info.dwMajorVersion, version_info.dwMinorVersion);
	printf("System metrics\n");
	printf("  SM_CLEANBOOT  : %d\n", GetSystemMetrics(SM_CLEANBOOT));
	printf("  SM_SLOWMACHINE: %d\n", GetSystemMetrics(SM_SLOWMACHINE));
	printf("System parameters\n");
	printf("  SPI_GETBEEP         : %d\n", beeper_enabled);
	printf("  SPI_GETFONTSMOOTHING: %d\n", font_smoothing);
	printf("  SPI_GETCURSORSHADOW : %d\n", mouse_shadow);
	printf("System time: %s\n", time_to_string(&system_time));
	printf("Local time : %s\n", time_to_string(&local_time));

	HINSTANCE instance = GetModuleHandle(NULL);
	WNDCLASSA clazz = { 0 };
	clazz.hInstance = instance;
	clazz.lpfnWndProc = WindowProc;
	clazz.hbrBackground = (HBRUSH)COLOR_WINDOW;
	clazz.lpszClassName = "MyApplication";
	if (!RegisterClassA(&clazz)) {
		fatal_error("unable to register window class (code %lu)", GetLastError());
	}

	HWND window = CreateWindowExA(
		0,
		clazz.lpszClassName,
		"Hello, Window!",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, instance, NULL
	);
	if (!window) {
		fatal_error("unable to create window (code %lu)", GetLastError());
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}