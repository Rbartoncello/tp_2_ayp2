cmake_minimum_required(VERSION 3.20)
project(tp_2_ayp2)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_2_ayp2 main.cpp casillero.h casillero.cpp casillero_construible.h casillero_construible.cpp
        casillero_inaccesible.cpp casillero_inaccesible.h casillero_transitable.h casillero_transitable.cpp
        colors.h emojis.h edificios.cpp edificios.h edificio.h edificio.cpp juego.cpp juego.h mapa.cpp mapa.h
        materiales.cpp materiales.h  material.cpp material.h)
