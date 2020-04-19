set(SOURCE_FILES median_structure_tests.cpp
        ${CMAKE_SOURCE_DIR}/src/median_structure.cpp)

add_executable(median_structure_tests ${SOURCE_FILES})

target_include_directories(median_structure_tests PUBLIC ${CMAKE_SOURCE_DIR}/include
                                                         ${CMAKE_SOURCE_DIR}/lib/googletest/include
                                                            ${CMAKE_SOURCE_DIR}/lib)

link_directories(median_structure_tests ${CMAKE_SOURCE_DIR}/lib/googletest/lib)

add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/googletest/lib/libgtest.a)

target_link_libraries(median_structure_tests gtest pthread)

target_compile_features(median_structure_tests PUBLIC cxx_std_14)

install(TARGETS median_structure_tests
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/release)