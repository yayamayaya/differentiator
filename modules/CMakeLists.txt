
file(GLOB DIRECS ./*)

foreach(item ${DIRECS})
	if(IS_DIRECTORY ${item})
		add_subdirectory(${item})
	endif()
endforeach()