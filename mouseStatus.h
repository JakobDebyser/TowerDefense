#ifndef _MOUSESTATUS
#define _MOUSESTATUS

class mouseStatus {
    public:
    enum STATUS {BUILDING_BASIC_TOWER, IDLE};

    mouseStatus() = default;
    constexpr mouseStatus(STATUS stat) : status(stat){};
    constexpr bool operator==(mouseStatus ms) const {return status == ms.status;};

    STATUS value(){return status;};

    private:
    STATUS status;
};

#endif