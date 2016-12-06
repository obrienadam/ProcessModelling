#include "Tee.h"

TJunction::TJunction()
    :
      Block(1, 2, 0, "Tee", "Tee")
{
    addProperty("K", 0.35, 0., 10);
}
