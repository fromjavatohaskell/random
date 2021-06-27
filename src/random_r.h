/* offset    |  size */  struct alt_random_data {
/*    0      |     8 */    int32_t *fptr;
/*    8      |     8 */    int32_t *rptr;
/*   16      |     8 */    int32_t *state;
/*   24      |     4 */    int rand_type;
/*   28      |     4 */    int rand_deg;
/*   32      |     4 */    int rand_sep;
/* XXX  4-byte hole  */
/*   40      |     8 */    int32_t *end_ptr;

                           /* total size (bytes):   48 */
                         };


extern int get_type_r(size_t n);
extern int alt_initstate_r (unsigned int seed, char *arg_state, size_t n, struct alt_random_data *buf);
extern int alt_setstate_r (char *arg_state, struct alt_random_data *buf);
extern int alt_srandom_r (unsigned int seed, struct alt_random_data *buf);
extern int alt_random_r (struct alt_random_data *buf, int32_t *result);
extern int alt_random_r_debug (struct alt_random_data *buf, int32_t *result, bool printDebug);
