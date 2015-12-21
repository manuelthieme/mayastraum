#include "../h/Animation.h"

/* constructor */
Animation::Animation(vector<string> images) : m_images(images) {
    if (this->m_images.size() > 0)
        this->m_activeImage = &(this->m_images[0]);
}

/* getter */
vector<string> Animation::images() const {
    return this->m_images;
}

string Animation::activeImage() const {
    return *this->m_activeImage;
}

/* setter */
void Animation::setImages(vector<string> images) {
    this->m_images = images;
}

void Animation::setActiveImage(string* activeImage) {
    this->m_activeImage = activeImage;
}


/* operators */
bool Animation::operator==(const Animation &a) const {
    return (a.m_images == this->m_images);
}
