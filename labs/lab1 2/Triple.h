/***
 * 
 * Complete your interface for Triple here
 *
 */


class Triple {
    public:
        Triple();
        Triple(double x, double y, double z);
        void setX(double val);
        void setY(double val);
        void setZ(double val);
        double getX() const;
        double getY() const;
        double getZ() const;


    private:
        double x;
        double y;
        double z;
};



