#include <stdio.h>
#include <flint/fmpz_mpoly_q.h>

void do_test(const fmpz_mpoly_ctx_t ctx) {
  flint_rand_t r;
  fmpz_mpoly_q_t a;

  flint_rand_init(r);
  gmp_randseed_ui(r->__gmp_state, 42);
  fmpz_mpoly_q_init(a, ctx);
  fmpz_mpoly_q_randtest(a, r, 3, 7, 3, ctx);

  fmpz_mpoly_q_print_pretty(a, NULL, ctx);

  flint_rand_clear(r);
  fmpz_mpoly_q_clear(a, ctx);
}

int main() {
  fmpz_mpoly_ctx_t ctx;
  fmpz_mpoly_ctx_init(ctx, 3, ORD_LEX);
  do_test(ctx);
  fmpz_mpoly_ctx_clear(ctx);
  return 0;
}
