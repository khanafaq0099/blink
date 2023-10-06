idf_component_register(SRCS "blink_example_main.c"
                    INCLUDE_DIRS "."
                    EMBED_TXTFILES ${CMAKE_CURRENT_SOURCE_DIR}/../server_certs/ca_cert.pem)

# set(COMPONENT_EMBED_TXTFILES ${CMAKE_CURRENT_SOURCE_DIR}/../server_certs/ca_cert.pem)
