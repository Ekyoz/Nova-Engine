# Core/test/CMakeLists.txt
add_executable(Core_test test.cpp)
target_link_libraries(Core_test PRIVATE Core)

# Activer les tests
add_test(NAME Core_test COMMAND Core_test)