# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krusto/Projects/uds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krusto/Projects/uds/build

# Include any dependencies generated for this target.
include CMakeFiles/UDS_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UDS_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UDS_app.dir/flags.make

CMakeFiles/UDS_app.dir/UDS/main.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/main.cpp.o: ../UDS/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UDS_app.dir/UDS/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/main.cpp.o -c /home/krusto/Projects/uds/UDS/main.cpp

CMakeFiles/UDS_app.dir/UDS/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/main.cpp > CMakeFiles/UDS_app.dir/UDS/main.cpp.i

CMakeFiles/UDS_app.dir/UDS/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/main.cpp -o CMakeFiles/UDS_app.dir/UDS/main.cpp.s

CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o: ../UDS/Application/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o -c /home/krusto/Projects/uds/UDS/Application/Application.cpp

CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Application/Application.cpp > CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.i

CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Application/Application.cpp -o CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o: ../UDS/Core/uds/uds_definitions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/uds_definitions.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/uds_definitions.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/uds_definitions.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o: ../UDS/Core/uds/uds_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/uds_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/uds_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/uds_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o: ../UDS/Core/uds/uds_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/uds_main.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/uds_main.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/uds_main.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/routine_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/routine_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/routine_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/routine_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/session_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/security_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/security_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/security_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/security_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o: ../UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o: ../UDS/Core/uds/UDS_Handlers/session_data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_data.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_data.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/session_data.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o: ../UDS/Core/uds/UDS_Handlers/memory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o -c /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/memory.cpp

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/memory.cpp > CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/uds/UDS_Handlers/memory.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o: ../UDS/Core/driver/can/can_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o -c /home/krusto/Projects/uds/UDS/Core/driver/can/can_handler.cpp

CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/driver/can/can_handler.cpp > CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/driver/can/can_handler.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.s

CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o: ../UDS/Core/driver/message_drv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o -c /home/krusto/Projects/uds/UDS/Core/driver/message_drv.cpp

CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/UDS/Core/driver/message_drv.cpp > CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.i

CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/UDS/Core/driver/message_drv.cpp -o CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.s

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o: ../Vendor/Socket/Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o -c /home/krusto/Projects/uds/Vendor/Socket/Client/Client.cpp

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/Vendor/Socket/Client/Client.cpp > CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.i

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/Vendor/Socket/Client/Client.cpp -o CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.s

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o: CMakeFiles/UDS_app.dir/flags.make
CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o: ../Vendor/Socket/Client/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o -c /home/krusto/Projects/uds/Vendor/Socket/Client/Socket.cpp

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krusto/Projects/uds/Vendor/Socket/Client/Socket.cpp > CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.i

CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krusto/Projects/uds/Vendor/Socket/Client/Socket.cpp -o CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.s

# Object files for target UDS_app
UDS_app_OBJECTS = \
"CMakeFiles/UDS_app.dir/UDS/main.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o" \
"CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o" \
"CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o" \
"CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o"

# External object files for target UDS_app
UDS_app_EXTERNAL_OBJECTS =

UDS_app: CMakeFiles/UDS_app.dir/UDS/main.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Application/Application.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_definitions.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/uds_main.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/routine_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/security_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/tester_present_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_data_by_id_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/read_mem_by_addr_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/write_mem_by_addr_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/session_data.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/uds/UDS_Handlers/memory.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/driver/can/can_handler.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/UDS/Core/driver/message_drv.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Client.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/Vendor/Socket/Client/Socket.cpp.o
UDS_app: CMakeFiles/UDS_app.dir/build.make
UDS_app: CMakeFiles/UDS_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krusto/Projects/uds/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable UDS_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UDS_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UDS_app.dir/build: UDS_app

.PHONY : CMakeFiles/UDS_app.dir/build

CMakeFiles/UDS_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UDS_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UDS_app.dir/clean

CMakeFiles/UDS_app.dir/depend:
	cd /home/krusto/Projects/uds/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krusto/Projects/uds /home/krusto/Projects/uds /home/krusto/Projects/uds/build /home/krusto/Projects/uds/build /home/krusto/Projects/uds/build/CMakeFiles/UDS_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UDS_app.dir/depend
