#include "../h/includes.h"

using namespace std;
/* constructor */
Animation::Animation(vector<string> images, int speed) : m_images(images), m_speed(speed) {
    if (this->m_images.size() > 0)
        this->m_activeImage = 0;
}

/* getter */
vector<string> Animation::images() const {
    return this->m_images;
}

string Animation::activeImage() const {
    return this->m_images[this->m_activeImage];
}

/* setter */
void Animation::setImages(vector<string> images) {
    this->m_images = images;
}

bool Animation::setActiveImage(string activeImage) {
    int i = 0;
    bool success = false;
    for (auto im: this->m_images) {
        if (im == activeImage) {
            this->m_activeImage = i;
            success = true;
            break;
        }
        ++i;
    }
    return success;
}

bool Animation::setActiveImage(int i) {
    if (i < int(this->m_images.size())) {
        this->m_activeImage = i;
        return true;
    }
    return false;
}

/* operators */
bool Animation::operator==(const Animation &a) const {
    return (a.m_images == this->m_images);
}

ostream& operator<<(ostream &output, const Animation &a) {
    output << "Animation:" << endl;
    for (auto i: a.images())
        output << "\t" << i << endl;
    output << endl;

    return output;
}

/* misc */
void Animation::tick(int t) {
    if (this->m_speed < 0)
        return;
    if (t % this->m_speed == 0) {
        this->m_activeImage++;
        this->m_activeImage %= this->m_images.size();
    }
}
