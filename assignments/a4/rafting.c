#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct point {
    int x;
    int y;
};

struct line {
    int x1;
    int y1;
    int x2;
    int y2;
};

/* get the distance between two points */
double point_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

/* get the shortest distance between a point and a line segment */
double point_line_dist(struct point *p, struct line *l) {
    /* normal vector and vector to project */
    int n_x = l->x1 - l->x2;
    int n_y = l->y1 - l->y2;
    int v_x = p->x - l->x2;
    int v_y = p->y - l->y2;

    /* project the vector v onto line */
    int numer = v_x * n_x + v_y * n_y;
    int denom = n_x * n_x + n_y * n_y;
    double scale = (numer + 0.0) / denom;
    double w_x = scale * n_x;
    double w_y = scale * n_y;
    w_x = l->x2 + w_x;
    w_y = l->y2 + w_y;

    /* calculate bounds of the line segment */
    int x1_larger = (l->x1 > l->x2);
    int y1_larger = (l->y1 > l->y2);
    int big_x = (x1_larger) ? l->x1 : l->x2;
    int small_x = (x1_larger) ? l->x2 : l->x1;
    int big_y = (y1_larger) ? l->y1 : l->y2;
    int small_y = (y1_larger) ? l->y2 : l->y1;

    double d = point_dist(p->x, p->y, w_x, w_y);
    if (w_x >= small_x && w_x <= big_x && w_y >= small_y && w_y <= big_y && d > 1e-9) {
        /* point is on line segment */
        return d;
    } else {
        /* chose one of the segment endpoints instead */
        double d1 = point_dist(p->x, p->y, l->x1, l->y1);
        double d2 = point_dist(p->x, p->y, l->x2, l->y2);
        return (d1 < d2) ? d1 : d2;
    }
}

int main() {
    int num_tests;
    scanf("%d", &num_tests);
    struct point inner_points[100];
    struct point outer_points[100];
    struct line inner_lines[100];
    struct line outer_lines[100];

    while (num_tests--) {
        int num_inner, num_outer, x, y;

        scanf("%d", &num_inner);
        for (int i=0; i<num_inner; ++i) {
            scanf("%d %d", &x, &y);
            inner_points[i].x = x;
            inner_points[i].y = y;
        }
        scanf("%d", &num_outer);
        for (int i=0; i<num_outer; ++i) {
            scanf("%d %d", &x, &y);
            outer_points[i].x = x;
            outer_points[i].y = y;
        }

        /* initialise array of lines */
        for (int i=0; i<num_inner; ++i) {
            int j = (i == 0) ? num_inner - 1 : i - 1;
            inner_lines[i].x1 = inner_points[j].x;
            inner_lines[i].y1 = inner_points[j].y;
            inner_lines[i].x2 = inner_points[i].x;
            inner_lines[i].y2 = inner_points[i].y;
        }
        for (int i=0; i<num_outer; ++i) {
            int j = (i == 0) ? num_outer - 1 : i - 1;
            outer_lines[i].x1 = outer_points[j].x;
            outer_lines[i].y1 = outer_points[j].y;
            outer_lines[i].x2 = outer_points[i].x;
            outer_lines[i].y2 = outer_points[i].y;
        }
        double min = DBL_MAX;
        for (int i=0; i<num_inner; ++i) {
            for (int j=0; j<num_outer; ++j) {
                /* compare inner points to outer lines */
                double d = point_line_dist(inner_points + i, outer_lines + j);
                if (d < min) {
                    min = d;
                }
                /* compare outer points to inner lines */
                d = point_line_dist(outer_points + j, inner_lines + i);
                if (d < min) {
                    min = d;
                }
            }
        }

        printf("%.10lf\n", min/2);
    }

    return 0;
}
