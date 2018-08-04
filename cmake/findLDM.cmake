if(LIBLDM_INCLUDE_DIRS AND LIBLDM_LIBRARIES)
    set(LIBLDM_FOUND TRUE)

else ()

    find_library (LIBLDM_LIBRARIES
        NAMES  fwupd libfwupd
    )
  
    find_path (LIBLDM_INCLUDE_DIRS
        NAMES fwupd.h
        PATH_SUFFIXES fwupd-1
        HINTS fwupd-1/libfwupd
    )
    
    if(LIBLDM_INCLUDE_DIRS AND LIBLDM_LIBRARIES)
        set(LIBLDM_FOUND TRUE)
    endif()
endif()

if (LIBLDM_FOUND)
    add_library(LIBLDM SHARED IMPORTED)
    set_target_properties(LIBLDM PROPERTIES
       INTERFACE_INCLUDE_DIRECTORIES ${LIBLDM_INCLUDE_DIRS}
       IMPORTED_LOCATION ${LIBLDM_LIBRARIES}
       ) 
endif()
