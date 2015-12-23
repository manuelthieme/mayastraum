#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
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
    friend ostream& operator<<(ostream &output, const Animation &a);

};

#endif /* ANIMATION_H */
