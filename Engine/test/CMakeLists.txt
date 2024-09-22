# Engine/test/CMakeLists.txt
add_executable(Engine_test test.cpp)
target_link_libraries(Engine_test PRIVATE Engine)

# Activer les tests
add_test(NAME Engine_test COMMAND Engine_test)