#pragma once

class RabbitPopulationModel {
private:
    int birth_rate;

public:
    RabbitPopulationModel(int rate);
    int calculate_population(int months) const;
};
