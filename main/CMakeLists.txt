set(SOURCES ./src/main.cpp)
idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS . include
        REQUIRES freertos freertos-addons esp_common gpio initsys I2Cbus PwmControl ssd1306)