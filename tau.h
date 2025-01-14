#pragma once

int tau_main(int argc, char* argv[]) {
	setup_exception_handler();
	run_tests();
	dump_memory_leaks();
	return 0;
}
