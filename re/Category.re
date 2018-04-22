open BsReactNative;

type category =
  | Eat
  | See
  | Stay;

type filter =
  | Category(category)
  | All;

module Style = {
  open BsReactNative.Style;
  let container =
    style([
      justifyContent(Center),
      paddingHorizontal(Pt(10.)),
      paddingBottom(Pt(7.)),
      paddingTop(Pt(10.)),
      borderBottomColor(Colors.white),
      borderBottomWidth(4.)
    ]);
  let content = style([fontSize(Float(20.)), textAlign(Center)]);
  let active = style([borderBottomColor(Colors.brainsYellow)]);
};

let component = ReasonReact.statelessComponent("RecommendationItem");

let make = (~filter: filter, ~currentFilter, ~onChange, _children) => {
  ...component,
  render: (_self) => {
    let active = filter == currentFilter;
    let name =
      switch filter {
      | All => "all"
      | Category(See) => "see"
      | Category(Eat) => "eat"
      | Category(Stay) => "stay"
      };
    let style =
      active ? BsReactNative.Style.flatten([|Style.container, Style.active|]) : Style.container;
    <TouchableOpacity style onPress=((_event) => onChange(filter))>
      <CustomText style=Style.content> (String.uppercase(name)) </CustomText>
    </TouchableOpacity>
  }
};