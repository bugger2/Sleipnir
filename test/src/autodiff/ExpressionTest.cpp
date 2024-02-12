// Copyright (c) Sleipnir contributors

#include <numbers>

#include <catch2/catch_test_macros.hpp>
#include <sleipnir/autodiff/Expression.hpp>

using sleipnir::detail::MakeExpressionPtr;
using sleipnir::detail::Zero;

TEST_CASE("Expression - Default constructor", "[Expression]") {
  auto expr = MakeExpressionPtr();

  CHECK(0.0 == expr->value);
  CHECK(sleipnir::ExpressionType::kConstant == expr->type);
}

TEST_CASE("Expression - Zero", "[Expression]") {
  CHECK(Zero()->IsConstant(0.0));
}

TEST_CASE("Expression - Prune multiply", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(zero * one == Zero());
  CHECK(zero * two == Zero());
  CHECK(one * zero == Zero());
  CHECK(one * one == one);
  CHECK(one * two == two);
  CHECK(two * one == two);
}

TEST_CASE("Expression - Prune divide", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(zero / one == Zero());
  CHECK(one / one == one);
  CHECK(two / one == two);
}

TEST_CASE("Expression - Prune binary plus", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(zero + zero == zero);
  CHECK(zero + one == one);
  CHECK(zero + two == two);
  CHECK(one + zero == one);
  CHECK(two + zero == two);
}

TEST_CASE("Expression - Prune binary minus", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(zero - zero == Zero());
  CHECK(one - zero == one);
  CHECK(two - zero == two);
}

TEST_CASE("Expression - Prune unary plus", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(+zero == Zero());
  CHECK(+one == one);
  CHECK(+two == two);
}

TEST_CASE("Expression - Prune unary minus", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(-zero == Zero());
}

TEST_CASE("Expression - Prune abs()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(abs(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune acos()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(acos(zero)->value == std::numbers::pi / 2.0);  // NOLINT
}

TEST_CASE("Expression - Prune asin()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(asin(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune atan()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(atan(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune atan2()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);

  CHECK(atan2(zero, one) == Zero());                         // NOLINT
  CHECK(atan2(one, zero)->value == std::numbers::pi / 2.0);  // NOLINT
}

TEST_CASE("Expression - Prune cos()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(cos(zero)->value == 1.0);  // NOLINT
}

TEST_CASE("Expression - Prune cosh()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(cosh(zero)->value == 1.0);  // NOLINT
}

TEST_CASE("Expression - Prune erf()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(erf(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune exp()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(exp(zero)->value == 1.0);  // NOLINT
}

TEST_CASE("Expression - Prune hypot()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);

  CHECK(hypot(zero, zero) == Zero());  // NOLINT
  CHECK(hypot(zero, one) == one);      // NOLINT
  CHECK(hypot(one, zero) == one);      // NOLINT
}

TEST_CASE("Expression - Prune log()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(log(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune log10()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(log10(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune pow()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);
  auto two = MakeExpressionPtr(2.0);

  CHECK(pow(zero, zero) == Zero());     // NOLINT
  CHECK(pow(zero, one) == Zero());      // NOLINT
  CHECK(pow(zero, two) == Zero());      // NOLINT
  CHECK(pow(one, zero) == one);         // NOLINT
  CHECK(pow(one, one) == one);          // NOLINT
  CHECK(pow(one, two) == one);          // NOLINT
  CHECK(pow(two, zero)->value == 1.0);  // NOLINT
  CHECK(pow(two, one) == two);          // NOLINT
}

TEST_CASE("Expression - Prune sign()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(sign(zero) == Zero());
}

TEST_CASE("Expression - Prune sin()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(sin(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune sinh()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(sinh(zero) == Zero());
}

TEST_CASE("Expression - Prune sqrt()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);
  auto one = MakeExpressionPtr(1.0);

  CHECK(sqrt(zero) == Zero());  // NOLINT
  CHECK(sqrt(one) == one);      // NOLINT
}

TEST_CASE("Expression - Prune tan()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(tan(zero) == Zero());  // NOLINT
}

TEST_CASE("Expression - Prune tanh()", "[Expression]") {
  auto zero = MakeExpressionPtr(0.0);

  CHECK(tanh(zero) == Zero());
}
