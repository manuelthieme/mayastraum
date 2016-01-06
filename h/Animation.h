#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Animation {
    /**
     * A list of Image Paths.
     */
    vector<string> m_images;
    /**
     * the index of the active image.
     */
    int m_activeImage;

    /**
     * The Speed of The Animation.
     * Describes the number of ticks until the image changes.
     */
    int m_speed;

public:
    /* constructor */
    /**
     * Constructor.
     * \param images The list of ImagPaths representing the Animation.
     * \param speed The speed of the Animation.
     */
    Animation(vector<string> images, int speed);

    /* getter */
    /**
     * Get all the ImagPaths of The Animation.
     */
    vector<string> images() const;
    /**
     *  Get the active ImagePath.
     */
    string activeImage() const;

    /* setter */
    /**
     * Override all ImagePaths.
     * \param images a list of ImagePaths.
     */
    void setImages(vector<string> images);
    /**
     * Set Active Image if in image List.
     * \param activeImage The ImagePath of the Image to set as active Image.
     * \return True if Path is in image List. Otherwise False.
     */
    bool setActiveImage(string activeImage);
    /**
     * Set ActiveImage if image List is large enough.
     * \param i index of image in image List.
     * \return True if image List is large enough. Otherwise False.
     */
    bool setActiveImage(int i);

    /* operators */
    bool operator==(const Animation &a) const;
    friend ostream& operator<<(ostream &output, const Animation &a);

    /* misc */
    /**
     * Changes activeImage if Time is right
     * \param t time to check against speed
     */
    void tick(int t);

};

#endif /* ANIMATION_H */
