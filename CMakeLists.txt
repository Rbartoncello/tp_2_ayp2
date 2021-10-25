cmake_minimum_required(VERSION 3.20)
project(tp_2_ayp2)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_2_ayp2 main.cpp casillero.cpp casillero.h casillero_construible.h casillero_construible.cpp
        casillero_inaccesible.h casillero_inaccesible.cpp casillero_transitable.cpp casillero_transitable.h
        mapa.h mapa.cpp edificios.h edificios.cpp mensajes_pantalla.cpp mensajes_pantalla.h menu.cpp menu.h
        colors.h emojis.h materiales.cpp)
