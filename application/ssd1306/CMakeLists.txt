set(SOURCES SSD1306.cpp)
idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS .
        REQUIRES driver I2Cbus log)