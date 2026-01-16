if(NOT TARGET StaticCrypto)
    find_path(CRYPTO_INCLUDE_DIR
        NAMES openssl/evp.h
        REQUIRED
    )

    # 修改 CMAKE_FIND_LIBRARY_SUFFIXES 前，先缓存，最后再还原
    set(__mycrypto_CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_FIND_LIBRARY_SUFFIXES})
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a .lib)

    find_library(CRYPTO_LIB
        NAMES crypto
        REQUIRED
    )

    add_library(StaticCrypto UNKNOWN IMPORTED)

    set_target_properties(
        StaticCrypto PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CRYPTO_INCLUDE_DIR}"
        IMPORTED_LOCATION "${CRYPTO_LIB}"
    )

    # 静态库 libcrypto.a 还需要链接 pthread 和 dl
    set_property(
        TARGET StaticCrypto
        PROPERTY
        INTERFACE_LINK_LIBRARIES pthread dl
    )

    set(CMAKE_FIND_LIBRARY_SUFFIXES ${__mycrypto_CMAKE_FIND_LIBRARY_SUFFIXES})
endif()