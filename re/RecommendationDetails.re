open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style([flex(1.), backgroundColor(Colors.white)]);
  let categories =
    style([
      height(60.),
      backgroundColor(Colors.white),
      paddingHorizontal(80.),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      alignItems(`center)
    ]);
};

let component = ReasonReact.statelessComponent("RecommendationDetails");

let make = (_children) => {
  ...component,
  render: (_self) => <ScrollView style=Style.container> <NavBar /> </ScrollView>
};

let jsComponent = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));