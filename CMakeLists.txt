cmake_minimum_required(VERSION 3.10)

project(STL_ATTEMPT)


#add_subdirectory(Tests)
add_executable(STL main.cpp vec.h)


#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
#target_link_libraries(run PRIVATE Threads::Threads)



target_include_directories(STL PUBLIC "${PROJECT_BINARY_DIR}")
#target_link_libraries(run ${llvm_libs})
#target_include_directories(Run_mutate PUBLIC "${PROJECT_BINARY_DIR}")
#target_link_libraries(Run_mutate ${llvm_libs})
