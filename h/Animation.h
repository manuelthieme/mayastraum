#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Animation {
    vector<string> m_images;
    int m_activeImage;

    int m_speed;

public:
    /* constructor */
    Animation(vector<string> images, int speed);

    /* getter */
    vector<string> images() const;
    string activeImage() const;

    /* setter */
    void setImages(vector<string> images);
    bool setActiveImage(string activeImage);
    bool setActiveImage(int i);

    /* operators */
    bool operator==(const Animation &a) const;
    friend ostream& operator<<(ostream &output, const Animation &a);

    /* misc */
    void tick(int t);

};

#endif /* ANIMATION_H */
