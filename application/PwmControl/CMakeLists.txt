set(SOURCES PCA9632.cpp)
idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS .
        REQUIRES log freertos driver I2Cbus)