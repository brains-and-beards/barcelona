open ReactNative;

module Style = {
  open ReactNative.Style;
  let container = style [flex 1., backgroundColor Colors.alabaster];
};

let component = ReasonReact.statelessComponent "RecommendationList";

let make _children => {
  ...component,
  render: fun _self => {
    let recommendations =
      Array.mapi
        (
          fun index place =>
            <RecommendationItem key=("recommendation-" ^ string_of_int index) place />
        )
        Recommendation.recommendations;
    <ScrollView style=Style.container>
      <NavBar />
      (ReasonReact.arrayToElement recommendations)
    </ScrollView>
  }
};
