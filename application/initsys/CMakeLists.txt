idf_component_register(SRC_DIRS src
        INCLUDE_DIRS include
        REQUIRES esp_common freertos freertos-addons
        PRIV_REQUIRES gpio PwmControl I2Cbus hardware)