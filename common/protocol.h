#pragma once
#pragma warning(disable: 4201)

typedef struct {
	char letter;
	char fs[10];
} DriveInfo;

typedef enum {
	REQ_NONE,
	REQ_UNARY,
	REQ_TIMER,
	REQ_REACTIVE,
	REQ_COUNT
} RequestKind;

static char* kind_names[] = {
	[REQ_UNARY] = "unary",
	[REQ_TIMER] = "timer",
	[REQ_REACTIVE] = "reactive"
};

typedef enum {
	TYPE_NONE,
	TYPE_HARD_DRIVE_INFO,
	TYPE_CPU_INFO,
	TYPE_FULL_RAM,
	TYPE_AVAILABLE_RAM,
	TYPE_COUNT
} RequestType, ResponseType;

static char* type_names[] = {
	[TYPE_HARD_DRIVE_INFO] = "hdinfo",
	[TYPE_CPU_INFO] = "cpuinfo",
	[TYPE_FULL_RAM] = "flram",
	[TYPE_AVAILABLE_RAM] = "avram"
};

typedef struct {
	RequestKind kind;
	RequestType type;
	uint32_t ts;
	union {
		uint32_t factor;
		// ...
	};
} Request;

static char* factor_names[] = {
	[0] = "B",
	[10] = "KB",
	[20] = "MB",
	[30] = "GB"
};

typedef enum {
	ERROR_NONE,
	ERROR_EMPTY_RESPONSE,
	ERROR_UNSUPPORTED_REQUEST_KIND,
	ERROR_UNSUPPORTED_REQUEST_TYPE
} ResponseError;

typedef struct {
	ResponseType type;
	ResponseError error;
	SYSTEMTIME time;
	uint32_t ts;
	union {
		struct {
			uint8_t count;
			DriveInfo infos[26];
		} hard_drive_info;
		unsigned long logical_cpu_count;
		struct {
			uint32_t factor;
			uint64_t value;
		} ram_info;
	};
} Response;