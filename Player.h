class Player{
    
    private:
        int cost;
        double points_scored;
    protected:
        String name, position;
        
    Player(int cost, int pts){
        this->cost = cost;
        this->points_scored = pts;
    }
    
    void setCost(int cost){}
    
    void setPoints(double points){}
    
    int getCost(){
        return this->cost;
    }
    
    double getPoints(){
           return this->points_scored;
    }
    
    double calculateValue() {}
    
}

