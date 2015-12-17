#include "../h/Animation.h"

/* constructor */
Animation::Animation() {
}

/* getter */
vector<string> Animation::Images() const {
    return this->images;
}

string* Animation::ActiveImage() const {
    return this->activeImage;
}

/* setter */
void Animation::setImages(vector<string> images) {
    this->images = images;
}

void Animation::setActiveImage(string* activeImage) {
    this->activeImage = activeImage;
}


/* operators */
bool Animation::operator==(const Animation &a) const {
    return (a.images == this->images);
}
