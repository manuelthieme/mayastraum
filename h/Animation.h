#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>

using namespace std;
class Animation {
    vector<string> m_images;
    string* m_activeImage;

public:
    /* constructor */
    Animation(vector<string> images);

    /* getter */
    vector<string> images() const;
    string activeImage() const;

    /* setter */
    void setImages(vector<string> images);
    void setActiveImage(string* activeImage);

    /* operators */
    bool operator==(const Animation &a) const;

};

#endif /* ANIMATION_H */
