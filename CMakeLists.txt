cmake_minimum_required(VERSION 3.20)

project(CoreLib)

include(CMakePackageConfigHelpers)

add_library(CoreLib)

target_compile_features(CoreLib
	PUBLIC
		cxx_std_20
)

target_sources(CoreLib
	PRIVATE
		src/core.cpp
		src/Logger.cpp
)

target_include_directories(CoreLib
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

# Cria o executável de teste.
add_executable(CoreLibTest
	tests/CoreLibTest.cpp
)

# Faz o teste utilizar a biblioteca CoreLib.
target_link_libraries(CoreLibTest
	PRIVATE
		CoreLib
)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/CoreLibConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/CoreLibConfig.cmake
	INSTALL_DESTINATION lib/cmake/CoreLib
)

install(
	TARGETS CoreLib
	EXPORT CoreLibTargets
)

install(
	DIRECTORY include/
	DESTINATION include
)

install(
	EXPORT CoreLibTargets
	FILE CoreLibTargets.cmake
	NAMESPACE CoreLib::
	DESTINATION lib/cmake/CoreLib
)

install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/CoreLibConfig.cmake
	DESTINATION
		lib/cmake/CoreLib
)