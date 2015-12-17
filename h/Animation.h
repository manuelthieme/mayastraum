#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>

using namespace std;
class Animation {
    vector<string> images;
    string* activeImage;

public:
    /* constructor */
    Animation();

    /* getter */
    vector<string> Images() const;
    string* ActiveImage() const;

    /* setter */
    void setImages(vector<string> images);
    void setActiveImage(string* activeImage);

    /* operators */
    bool operator==(const Animation &a) const;

};

#endif /* ANIMATION_H */
