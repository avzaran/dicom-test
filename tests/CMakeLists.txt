find_package(Qt6 REQUIRED COMPONENTS Test)

set(TEST_SOURCES
    test_load.cpp
    test_sync.cpp
    test_measure.cpp
)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests PRIVATE Qt6::Test Qt6::Widgets)

add_test(NAME dicom_tests COMMAND tests)
