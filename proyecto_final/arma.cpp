#include "arma.h"

arma::arma(unsigned int scale) {
    pixmap_management = new sprites(":/nive1/personaje/pngkit_game-sprite-png_2414663.png",scale);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(arma_x_size, arma_y_size);
    //setPixmap();
    set_animations();
    setX(1*arma_y_size*scale);
    setY(1*arma_x_size*scale);
    setPixmap(pixmap_management->get_current_pixmap(0));
}
