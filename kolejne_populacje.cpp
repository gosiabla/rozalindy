#include "kolejne_populacje.h"

RabbitPopulationModel::RabbitPopulationModel(int rate) : birth_rate(rate) {}

int RabbitPopulationModel::calculate_population(int months) const {
    if (months <= 0) return 0;
    if (months <= 2) return 1;

    int current = 1;
    int previous = 1;

    for (int i = 3; i <= months; i++) {
        int next = current + birth_rate * previous;
        previous = current;
        current = next;
    }

    return current;
}
