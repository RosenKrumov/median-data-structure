set(SOURCE_FILES main.cpp
        median_structure.cpp)

add_executable(median_structure ${SOURCE_FILES})

target_include_directories(median_structure PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(median_structure PUBLIC cxx_std_14)

install(TARGETS median_structure
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/release)