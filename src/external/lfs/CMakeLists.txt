set(EXTERNAL_LFS
	${CMAKE_CURRENT_LIST_DIR}/src/lfs.c
)

add_library(lfs STATIC ${EXTERNAL_LFS})
