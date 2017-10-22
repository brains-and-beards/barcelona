open ReactNative;

type filter =
  | Category Recommendation.category
  | All;

module Style = {
  open ReactNative.Style;
  let container =
    style [
      justifyContent `center,
      paddingHorizontal 10.,
      paddingBottom 7.,
      paddingTop 10.,
      borderBottomColor Colors.white,
      borderBottomWidth 4.
    ];
  let content = style [fontSize 20., textAlign `center];
  let active = style [borderBottomColor Colors.brainsYellow];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make filterCategory::(filterCategory: filter) ::currentFilter _children => {
  ...component,
  render: fun _self => {
    let active = filterCategory == currentFilter;
    let name =
      switch filterCategory {
      | All => "all"
      | Category See => "see"
      | Category Eat => "eat"
      | Category Stay => "stay"
      };
    let style =
      active ? ReactNative.Style.flatten [|Style.container, Style.active|] : Style.container;
    <View style> <CustomText style=Style.content> (String.uppercase name) </CustomText> </View>
  }
};
