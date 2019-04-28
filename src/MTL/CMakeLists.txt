# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (MTL 
	list.hpp 
	listnode.hpp
	shared_ptr.hpp)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (MTL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})