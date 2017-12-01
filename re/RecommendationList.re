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

let component = ReasonReact.statelessComponent("RecommendationList");

let make = (~navigation, _children) => {
  ...component,
  render: (_self) => {
    let recommendations =
      Array.mapi(
        (index, place) =>
          <RecommendationItem navigation key=("recommendation-" ++ string_of_int(index)) place />,
        Recommendation.recommendations
      );
    <ScrollView style=Style.container>
      <NavBar />
      (ReasonReact.arrayToElement(recommendations))
    </ScrollView>
  }
};

let jsComponent =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~navigation=jsProps##navigation, [||])
  );