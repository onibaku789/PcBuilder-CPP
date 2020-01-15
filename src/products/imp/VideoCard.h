//
// Created by Narancs on 2020. 01. 06..
//

#ifndef PCBUILDER_VIDEOCARD_H
#define PCBUILDER_VIDEOCARD_H


#include <ostream>
#include "../Product.h"

class VideoCard : public Product {
    int memory;
    int hz;
public:
    VideoCard();

    VideoCard(int initPrice, time_t dateOfAcq, const std::string &name, int memory, int hz);

    VideoCard(const VideoCard &other) noexcept;

    VideoCard &operator=(const VideoCard &other) noexcept;

    VideoCard(VideoCard &&other) noexcept;

    VideoCard &operator=(VideoCard &&other) noexcept;

    ~VideoCard() override;

    double getCurrentPrice() const override;

    std::string getType() const override;

    char getCharCode() const override;

    bool operator==(const VideoCard &rhs) const;

    bool operator!=(const VideoCard &rhs) const;


protected:
    void printParams(std::ostream &ostream) const override;

    void loadParamsFromStream(std::istream &istream) override;

    void writeParamsToStream(std::ostream &ostream) const override;

};


#endif //PCBUILDER_VIDEOCARD_H
