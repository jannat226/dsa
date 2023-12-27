// podcast.h
#ifndef PODCAST_H
#define PODCAST_H

struct Episode
{
    int episodeID;
    char name[50];
    char host[50];
    char status[20];
    int totalContribution;
};

int insertEpisode(struct Episode episodes[], int *outRows, int *outCols);
void deleteEpisode(struct Episode episodes[], int *count);
void displayEpisodes(const struct Episode episodes[], int count);
int linearSearch(const struct Episode episodes[], int count, const char *targetName);
void totalContribution();
void averageContribution();

#endif
