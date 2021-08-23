set(SOURCES ./src/main.cpp)
idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS . include
        PRIV_REQUIRES initsys log freertos freertos-addons)