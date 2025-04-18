#include <flint/flint.h>
#include <flint/fmpz_mpoly_q.h>

#include <iostream>
#include <iterator>
#include <memory>

auto make_fmpz_mpoly_ctx(slong nvars, ordering_t ord)
{
  auto raw = new fmpz_mpoly_ctx_struct;
  fmpz_mpoly_ctx_init(raw, nvars, ord);
  auto deleter = [](fmpz_mpoly_ctx_struct *p)
  {
    fmpz_mpoly_ctx_clear(p);
    delete p;
  };
  return std::unique_ptr<fmpz_mpoly_ctx_struct, decltype(deleter)>(raw, deleter);
};

auto make_fmpz_mpoly_q(const char *str, const char **x, const fmpz_mpoly_ctx_struct &ctx)
{
  auto raw = new fmpz_mpoly_q_struct;
  fmpz_mpoly_q_init(raw, &ctx);
  fmpz_mpoly_q_set_str_pretty(raw, str, x, (fmpz_mpoly_ctx_struct *)&ctx); // https://github.com/flintlib/flint/issues/2304
  auto deleter = [&](fmpz_mpoly_q_struct *p)
  {
    fmpz_mpoly_q_clear(p, &ctx);
    delete p;
  };
  return std::unique_ptr<fmpz_mpoly_q_struct, decltype(deleter)>(raw, deleter);
};

int main()
{
  std::cout << FLINT_VERSION << std::endl;

  const char *var_names[] = {"x", "y", "z"};
  constexpr slong nvars = std::size(var_names);

  auto ctx = make_fmpz_mpoly_ctx(nvars, ORD_DEGREVLEX);

  auto p = make_fmpz_mpoly_q("(x^2 + y + z) / (x - y)", var_names, *ctx);
  auto q = make_fmpz_mpoly_q("(x - y - x^2*z - y*z - z^2) / ((x - y)*z)", var_names, *ctx);
  auto r = make_fmpz_mpoly_q("1", var_names, *ctx);

  fmpz_mpoly_q_add(&*r, &*p, &*q, &*ctx);

  fmpz_mpoly_q_print_pretty(&*r, var_names, &*ctx); // = 1 / z
  std::printf("\n");

  return 0;
}
