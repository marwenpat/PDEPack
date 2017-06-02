# --------------------------------------------------------
#  Iterative Verfahren für LGS
# --------------------------------------------------------
# Jacobi - Gesamtschrittverfahren
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/matrix1.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable (jacobiTest EXCLUDE_FROM_ALL jacobiTest.cpp matrix1.txt)
add_executable (gaussSeidelTest EXCLUDE_FROM_ALL gaussSeidelTest.cpp matrix1.txt)

TARGET_LINK_LIBRARIES(jacobiTest pdepack)
TARGET_LINK_LIBRARIES(gaussSeidelTest pdepack)

