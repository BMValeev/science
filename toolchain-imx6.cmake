# Prerequisites:
#  * Set the Linux environment variable SYSROOTS to the sysroots directory of
#    of your Yocto SDK (e.g., /opt/imx6/sdk/sysroots).
#  * Set the Linux environment variable QT_BIN_PATH to the directory containing
#    qmake, moc and rcc on your Linux host (e.g., /opt/Qt5.7.1/5.7/gcc_64/bin).


set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv7-a)

set(TOOLCHAIN_PREFIX /usr/local/oecore-x86_64/sysroots/x86_64-oesdk-linux/usr/bin/arm-oe-linux-gnueabi/arm-oe-linux-gnueabi-)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)

set(SYSROOTS /usr/local/oecore-x86_64/sysroots)
set(CMAKE_SYSROOT ${SYSROOTS}/cortexa9hf-neon-oe-linux-gnueabi)
set(CMAKE_PREFIX_PATH ${CMAKE_SYSROOT}/usr/lib/cmake)
set(QT_BIN_PATH ${SYSROOTS}/x86_64-oesdk-linux/usr/bin/qt5)
set(OE_QMAKE_PATH_EXTERNAL_HOST_BINS ${QT_BIN_PATH})

#set(CMAKE_IMPORT_LIBRARY_PREFIX ${SYSROOTS})
set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(COMPILER_FLAGS " -march=armv7-a -marm -mfpu=neon  -mfloat-abi=hard -mcpu=cortex-a9")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}" CACHE STRING "" FORCE)
link_directories(${CMAKE_SYSROOT}/usr/lib)