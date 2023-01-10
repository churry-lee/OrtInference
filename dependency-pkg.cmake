find_package(PkgConfig REQUIRED)
pkg_check_modules(ONNXRUNTIME REQUIRED IMPORTED_TARGET libonnxruntime)
pkg_check_modules(OPENCV REQUIRED IMPORTED_TARGET opencv4)
pkg_check_modules(SPDLOG REQUIRED IMPORTED_TARGET spdlog)
pkg_check_modules(FMT REQUIRED IMPORTED_TARGET FMT)

set(LOCAL_INCLUDE_DIRS /usr/local/include)
set(LOCAL_LIBRARY_DIRS /usr/local/lib)

# Dependency 관련 변수 설정
set(DEP_INCLUDE_DIRS
        ${LOCAL_INCLUDE_DIRS}
        ${SPD_INCLUDE_DIRS} ${FMT_INCLUDE_DIRS}
        ${ONNXRUNTIME_INCLUDE_DIRS}
        ${OPENCV_INCLUDE_DIRS}
        )
set(DEP_LIBRARY_DIRS
        ${LOCAL_LIBRARY_DIRS}
        ${SPD_LIBRARY_DIRS} ${FMT_LIBRARY_DIRS}
        ${ONNXRUNTIME_LIBRARY_DIRS}
        )
set(DEP_LIBRARIES
        ${SPD_LIBRARIES} ${FMT_LIBRARIES}
        ${ONNXRUNTIME_LIBRARIES}
        ${OPENCV_LDFLAGS} ${OPENCV_LIBRARIES}
        )
