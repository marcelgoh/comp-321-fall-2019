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

double point_dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double point_line_dist(struct point *p, struct line *l) {
    int s_x = l->x1 - l->x2;
    int s_y = l->y1 - l->y2;

    int numer = p->x * s_x + p->y * s_y;
    int denom = s_x * s_x + s_y * s_y;
    double scale = (numer + 0.0) / denom;
    double w_x = scale * s_x;
    double w_y = scale * s_y;
    w_x = l->x1 - w_x;
    w_y = l->y1 - w_y;
    //printf("Point: (%d, %d), Line: (%d, %d)--(%d, %d), s_x: %d, s_y: %d, numer: %d, denom: %d, scale: %.4g, w_x: %.4g, w_y: %.4g\n", p->x, p->y, l->x1, l->y1, l->x2, l->y2, s_x, s_y, numer, denom, scale, w_x, w_y);

    int x1_larger = (l->x1 > l->x2);
    int y1_larger = (l->y1 > l->y2);
    int big_x = (x1_larger) ? l->x1 : l->x2;
    int small_x = (x1_larger) ? l->x2 : l->x1;
    int big_y = (y1_larger) ? l->y1 : l->y2;
    int small_y = (y1_larger) ? l->y2 : l->y1;

    double d = point_dist(p->x, p->y, w_x, w_y);
    if (w_x >= small_x && w_x <= big_x && w_y >= small_y && w_y <= big_y && d > 1e-9) {
        return d;
    } else {
        double d1 = point_dist(p->x, p->y, l->x1, l->y1);
        double d2 = point_dist(p->x, p->y, l->x2, l->y2);
        double min = (d1 < d2) ? d1 : d2;

        //printf("%f\n", min);
        return min;
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
                double d = point_line_dist(inner_points + i, outer_lines + j);
                if (d < min) {
                    min = d;
                }
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
