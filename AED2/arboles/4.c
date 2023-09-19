/*
// pre-orden: raiz - izquierda - derecha 54 -> (-72) -> (-25) -> (-10) -> (-15) -> (-5)
// in-orden: izquierda- raiz - derecha  (-72) -> (-25) -> (-15) -> (-10) -> (-5) -> 54
// post-orden: izquierda - derecha - raiz  (-15) -> (-5) -> (-10) -> (-25) -> (-72) -> 54
//                        54
//                       /  \
//                      /    \
//                    -72
//                    /  \
//                   /    \
//                        -25
//                           \
//                            \
//                            -10
//                            /  \
//                           /    \
//                         -15    -5
//
// siempre se recorre primero la izquierda y luego la derecha, lo unico que cambia es cuando se recorre la raiz
//
//                       74
//                      /  \
//                     /    \
//                    /     125
//                  -22     /
//                  /  \   35
//                 /    \
//              -150    -10
//
// pre-orden raiz - izquierda - derecha 54 -> (-22) -> -150 -> (-10) -> 125 -> 35
// in-orden izquierda - raiz - derecha  (-150) -> (-22) -> (-10) -> 74 -> 35 -> 125
// post-orden izquierda - derecha - raiz (-150) -> -10 -> (-22) -> 35 -> 125 -> 74
//
//
//
//
//
//
//
*/