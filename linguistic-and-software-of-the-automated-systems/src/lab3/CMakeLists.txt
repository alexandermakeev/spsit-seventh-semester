set(SOURCE_FILES main.cpp Util.cpp Util.h File.cpp File.h exceptions/DirDoesNotExistException.cpp exceptions/DirDoesNotExistException.h)
add_executable(lab3 ${SOURCE_FILES})
add_subdirectory(exceptions)